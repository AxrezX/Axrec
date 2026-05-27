# n = int(input())

# def is_prime0(n):
#     if n <= 1:
#         return False
#     for i in range(2, n):
#         if n % i == 0:
#             return False
#     return True



# def is_prime1(n):
#     if n < 2:
#         return False
#     limit = int(n ** 0.5) + 1
#     for i in range(2, limit):
#         if n % i == 0:
#             return False
#     return True



# def is_prime2(n):
#     if n < 2:
#         return False
#     if n == 2:
#         return True
#     if n % 2 == 0
#         return False

#     i = 3
#     while i * i <= n:
#         if n % i == 0:
#             return False
#         i += 2
#     return True



# def is_prime3(n):
#     if n < 2:
#         return False
#     if n <= 3:
#         return True
#     if n % 2 == 0 or n % 3 == 0:
#         return False

#     i = 5
#     while i * i <= n:
#         if n % i == 0 or n % (i + 2) == 0:
#             return False
#         i += 6
#     return True



def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def first_n_primes(n):
    primes = []
    num = 2
    while len(primes) < n:
        if is_prime(num):
            primes.append(num)
        num += 1
    return primes


def nth_prime(n):
    count = 0
    num = 2
    while True:
        if is_prime(num):
            count += 1
            if count == n:
                return num
        num += 1


# ===== 测试 =====
print(is_prime(19))
print(first_n_primes(10))
print(nth_prime(100))