import pyopencl as cl
import numpy as np
import time

N = 40000000 

A = np.random.rand(N).astype(np.float32)
B = np.random.rand(N).astype(np.float32)

start_cpu = time.time()
C_cpu = A + B
end_cpu = time.time()


platform = cl.get_platforms()[0]
device = platform.get_devices()[0]
ctx = cl.Context([device])
queue = cl.CommandQueue(ctx)

kernel_code = """
__kernel void vector_add(__global float* A, __global float* B, __global float* C) {
    int i = get_global_id(0);
    C[i] = A[i] + B[i];
}
"""

program = cl.Program(ctx, kernel_code).build()

mf = cl.mem_flags
A_buf = cl.Buffer(ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=A)
B_buf = cl.Buffer(ctx, mf.READ_ONLY | mf.COPY_HOST_PTR, hostbuf=B)
C_buf = cl.Buffer(ctx, mf.WRITE_ONLY, A.nbytes)

start_gpu = time.time()
program.vector_add(queue, A.shape, None, A_buf, B_buf, C_buf)
queue.finish()
end_gpu = time.time()

C_gpu = np.empty_like(A)
cl.enqueue_copy(queue, C_gpu, C_buf)

print(" Match?" , np.allclose(C_cpu, C_gpu, atol=1e-6))
print(" CPU Time: {:.6f} seconds".format(end_cpu - start_cpu))
print(" GPU Time: {:.6f} seconds".format(end_gpu - start_gpu))

