import pyopencl as cl
import numpy as np
import time


N = 10000

A = np.random.rand(N, N).astype(np.float32)
B = np.random.rand(N, N).astype(np.float32)

start_cpu = time.time()
C_cpu = np.dot(A, B)
end_cpu = time.time()


platform = cl.get_platforms()[0]
device = platform.get_devices()[0]
ctx = cl.Context([device])
queue = cl.CommandQueue(ctx)

kernel_code = """
__kernel void mat_mul(const int N,
                      __global float* A,
                      __global float* B,
                      __global float* C) {
    int row = get_global_id(0);
    int col = get_global_id(1);

    float sum = 0.0f;
    for (int k = 0; k < N; ++k) {
        sum += A[row * N + k] * B[k * N + col];
    }
    C[row * N + col] = sum;
}
"""

program = cl.Program(ctx, kernel_code).build()


A_flat = A.flatten()
B_flat = B.flatten()
C_flat = np.empty_like(A_flat)

mf = cl.mem_flags
A_buf = cl.Buffer(ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=A_flat)
B_buf = cl.Buffer(ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=B_flat)
C_buf = cl.Buffer(ctx, mf.WRITE_ONLY, A_flat.nbytes)

start_gpu = time.time()
program.mat_mul(queue, (N, N), None, np.int32(N), A_buf, B_buf, C_buf)
queue.finish()
end_gpu = time.time()

cl.enqueue_copy(queue, C_flat, C_buf)
C_gpu = C_flat.reshape((N, N))


print(" Match?", np.allclose(C_cpu, C_gpu, atol=1e-3))
print(" CPU Time: {:.6f} seconds".format(end_cpu - start_cpu))
print(" GPU Time: {:.6f} seconds".format(end_gpu - start_gpu))
