import time

def is_prime(number):
	if number<=1:
		return False
	for i in range(2,int(number**0.5)+1):
		if number%i==0:
			return False
	return True

def count_primes(target):
	count=0
	for i in range(2,target):
		if is_prime(i):
			count+=1
	return count

start=time.time()
prime_count=count_primes(100000)
end=time.time()

print(f"Found {prime_count} primes")
print(f"Time taken by single thread: {end-start:.2f} seconds")
