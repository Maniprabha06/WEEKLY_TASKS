import time
import multiprocessing

def is_prime(n):
	if n<=1:
		return False
	for i in range(2,int(n**0.5)+1):
		if n%i==0:
			return False
	return True

def count_primes(start,end):
	count=0
	for i in range(start,end):
		if is_prime(i):
			count+=1
	return count

if __name__ == "__main__":
	start_time=time.time()
	with multiprocessing.Pool(processes=2) as pool:
		results=pool.starmap(count_primes,[(2,5000),(5000,10000)])

	total=sum(results)
	end_time=time.time()

	print(f"Total primes : {total}")
	print(f"Time taken by multiprocessing):{end_time-start_time:.2f} seconds")
