def isPass(i):
    def tobin(n):
        return bin(n)[2:]

    def to4bin(n):
        b = tobin(n)
