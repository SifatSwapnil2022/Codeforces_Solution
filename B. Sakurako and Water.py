def main():
    test_cases = int(input())
    
    for _ in range(test_cases):
        the_number = int(input())
        a = [[0] * the_number for _ in range(the_number)]  # Initialize 2D array

        # Read the matrix
        for i in range(the_number):
            row = list(map(int, input().split()))
            for j in range(the_number):
                a[i][j] = row[j]
        
        # Initialize the diff array
        diff = [float('inf')] * (2 * the_number - 1)

        # Fill the diff array with minimum values
        for i in range(the_number):
            for j in range(the_number):
                idx = i - j + (the_number - 1)
                diff[idx] = min(diff[idx], a[i][j])
        
        ans = 0
        for value in diff:
            if value < 0:
                ans -= value  # Accumulate the negative values

        print(ans)

if __name__ == "__main__":
    main()
