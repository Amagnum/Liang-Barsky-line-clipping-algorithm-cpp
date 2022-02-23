# Liang-Barsky-line-clipping-algorithm-cpp
Liang Barsky line clipping algorithm cpp code with all intermediate steps

## Run
```
g++ liang_barsky.cpp > eliang
./eliang < liang.in
```

# Input format
```
Xmin Xmax Ymin Ymax
P1x P1y
P2x P2y
```

# Output
```
p1 = -Δx = -50      q1 = x1 - x_min = -20
p2 = Δx  = 50      q2 = x_max - x1 = 70
p3 = -Δy = -70      q3 = y1 - y_min = -10
p4 = Δy  = 70      q4 = y_max - y1 = 60

for Left : 
	Potential Entering
	t = -20/-50 = 0.4
for Right : 
	Potential Leaving
	t = 70/50 = 1.4
for Bottom : 
	Potential Entering
	t = -10/-70 = 0.142857
for Top : 
	Potential Leaving
	t = 60/70 = 0.857143

t_min = max(0, all_t_PE) = 0.4
t_max = min(1, all_t_PL) = 0.857143

point corresponding to t_min :
```
