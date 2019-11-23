# Reflection

## Program description
// Describe your program using your own words.

## `Route` Member Function Test cases
### Test case 1: `name_` accessor and mutator

****Class name:**** `Route`

**Object state:** All data members are not initialized

**Function name:** `set_name`

**Parameters:** "57X Brea Mall Express"

**Command line input:** None

**Returned value:** None

**Command line output:** None

**Other expected behavior:** `name()` output is "57X Brea Mall Express"

### Test case 2: `departure_time_` accessor and mutator

****Class name:**** `Route`

**Object state:** All data members are not initialized

**Function name:** `set_departure_time`

**Parameters:** 1623

**Command line input:** None

**Returned value:** None

**Command line output:** None

**Other expected behavior:** `departure_time()` output is 1623

### Test case 3: `arrival_time_` accessor and mutator

****Class name:**** `Route`

**Object state:** All data members are not initialized

**Function name:** `set_arrival_time`

**Parameters:** 1623

**Command line input:** None

**Returned value:** None

**Command line output:** None

**Other expected behavior:** `arrival_time()` output is 1637

### Test case 4: `display` screen output

**Class name:** `Route`

**Object state:** 
- `name_` is "57X Brea Mall Express"
- `departure_time_` is 1623
- `arrival_time_` is 1637

**Function name:** `display`

**Parameters:** None

**Command line input:** None

**Returned value:** None

**Command line output:** 
```
Route: 57X Brea Mall Express
Departure time: 1623
Arrival time: 1637
```

**Other expected behavior:** None

### Test case n: Test case name

**Class name:**

**Object state:**

**Function name:**

**Parameters:**

**Command line input:**

**Returned value:**

**Command line output:** 

**Other expected behavior:** None

## Function Test cases
### Test case 1: `Route` object creation

**Function name:** `create_route`

**Parameters:** None

**Command line input:**
```
57X Brea Mall Express
1623
1637
```

**Returned value:** 
- `Route` object
  - `name_` is "57X Brea Mall Express"
  - `departure_time` is 1623
  - `arrival_time` is 1637.

**Command line output:** None

**Other expected behavior:** None

### Test case 2: Display array with two values

**Function name:** `display_routes`

**Parameters:** 
- Array of two `Route` objects
  - 0
    - 57X Brea Mall Express
    - 1632
    - 1637
  - 1
    - 153 Brea Mall
    - 1642
    - 1703
- 2


**Command line input:** None

**Returned value:** None

**Command line output:**
```
Route name: 57X Brea Mall Express
Departure time: 1632
Arrival time: 1637

Route name: 153 Brea Mall
Departure time: 1642
Arrival time: 1703
```

**Other expected behavior:** None

### Test case 3: Display array with no values

**Function name:** `display_routes`

**Parameters:** 
- Empty array
- 0


**Command line input:** None

**Returned value:** None

**Command line output:** None

**Other expected behavior:** None

### Test case 4: Display array with one value

**Function name:** `display_routes`

**Parameters:** 
- Array of one `Route` object
  - 0
    - 57X Brea Mall Express
    - 1632
    - 1637
- 1

**Command line input:** None

**Returned value:** None

**Command line output:**
```
Route name: 57X Brea Mall Express
Departure time: 1632
Arrival time: 1637
```
**Other expected behavior:** None

### Test case 5: User provides a time to leave

**Function name:** `get_time_to_leave`

**Parameters:** None

**Command line input:** 1100

**Returned value:** 1100

**Command line output:** None

**Other expected behavior:** None

### Test case 6: Find a route from an empty array

**Function name:** `find_route`

**Parameters:** 
- Empty Route array
- 0
- 1100

**Command line input:** None

**Returned value:** None

**Command line output:** 
```
Sorry, there are no routes available.
```

**Other expected behavior:** None

### Test case n: Test case name

**Function name:** 

**Parameters:** 

**Command line input:**

**Returned value:**

**Command line output:**

**Other expected behavior:**

## Issues encountered
### Open issues
//Describe each of the issues you are currently having with your program. If you had more time, describe how you would you fixed the issue. If there are no open issues then just say "No open issues".

### Resolved issues
// Describe the issues you encountered while developing your project and how you resolved them.