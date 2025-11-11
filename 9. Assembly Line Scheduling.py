"""Task: Given two assembly lines, each with n stations, along with the processing time at each station, the entry time for each line, and the exit time for each line. You are also given the transfer times between stations on opposite lines. Find the minimum time to manufacture a chassis."""

# TC: O(n) where n is the number of stations
# SC: O(n) for the DP arrays
def assembly_line_scheduling(a1, a2, t1, t2, e1, e2, x1, x2):
    n = len(a1)
    
    # dp1[i] = minimum time to reach station i on line 1
    # dp2[i] = minimum time to reach station i on line 2
    dp1 = [0] * n
    dp2 = [0] * n
    
    # Base case: first station
    dp1[0] = e1 + a1[0]
    dp2[0] = e2 + a2[0]
    
    # Fill the DP arrays
    for i in range(1, n):
        # Minimum time to reach station i on line 1
        # Either from previous station on line 1 or transfer from line 2
        dp1[i] = min(dp1[i - 1] + a1[i], dp2[i - 1] + t2[i - 1] + a1[i])
        
        # Minimum time to reach station i on line 2
        # Either from previous station on line 2 or transfer from line 1
        dp2[i] = min(dp2[i - 1] + a2[i], dp1[i - 1] + t1[i - 1] + a2[i])
    
    # Return minimum of exiting from either line
    return min(dp1[n - 1] + x1, dp2[n - 1] + x2)

# Space Optimized Version
# TC: O(n)
# SC: O(1) - constant space
def assembly_line_scheduling_optimized(a1, a2, t1, t2, e1, e2, x1, x2):
    n = len(a1)
    
    # Current minimum times for both lines
    time1 = e1 + a1[0]
    time2 = e2 + a2[0]
    
    for i in range(1, n):
        new_time1 = min(time1 + a1[i], time2 + t2[i - 1] + a1[i])
        new_time2 = min(time2 + a2[i], time1 + t1[i - 1] + a2[i])
        
        time1 = new_time1
        time2 = new_time2
    
    return min(time1 + x1, time2 + x2)

if __name__ == "__main__":
    n = int(input("Enter number of stations: "))
    
    a1 = list(map(int, input("Enter processing times for line 1: ").split()))
    a2 = list(map(int, input("Enter processing times for line 2: ").split()))
    
    t1 = list(map(int, input("Enter transfer times from line 1 to line 2: ").split()))
    t2 = list(map(int, input("Enter transfer times from line 2 to line 1: ").split()))
    
    e1 = int(input("Enter entry time for line 1: "))
    e2 = int(input("Enter entry time for line 2: "))
    x1 = int(input("Enter exit time for line 1: "))
    x2 = int(input("Enter exit time for line 2: "))
    
    min_time = assembly_line_scheduling_optimized(a1, a2, t1, t2, e1, e2, x1, x2)
    print(f"Minimum time to manufacture: {min_time}")
