import time
import threading

def is_prime(number):
	if number<=1:
		return False
	for i in range(2,int(number**0.5)+1):
		if number%i==0:
			return False
	return True

def count_primes(start,end,result,index):
	count=0
	for i in range(start,end):
		if is_prime(i):
			count+=1
	result[index]=count

start_time=time.time()

limit=200000
mid=limit//2
results=[0,0]

t1=threading.Thread(target=count_primes,args=(2,mid,results,0))
t2=threading.Thread(target=count_primes,args=(mid,limit,results,1))

t1.start()
t2.start()
t1.join()
t2.join()

total_prime=results[0]+results[1]
end_time=time.time()

print(f"Found {total_prime} primes")
print(f"Time taken by multithread: {end_time - start_time:.2f} seconds") 
