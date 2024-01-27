def is_prime(n):
    nums_to_check = range(2, int(n**.5) + 1)
    for i in nums_to_check:
        if n % i == 0:
            return False
    return True

def prime_at_index(idx):
    n_primes = 1
    n = 2
    while n_primes < idx:
        n+=1
        if is_prime(n):
            n_primes += 1
    return n

print(prime_at_index(10001))


#To find the 10,001st prime number, make an algorithm that calculates if a number is prime and increases a count or adds the number to a list
#until that count or len(list) hits 10,0001

# number=2
# prime_list=[number]
# while len(prime_list)<10001:
#     number+=1
#     v=0
#     for i in prime_list:
#         if number%i==0:
#             v=1
#             break
#     if v==0:
#         prime_list.append(number)
# print(prime_list)