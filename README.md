# Lem_in
Project for school 21 by lhaired and Gdoze

## Challenge
Find the shortest path to get **n** ants across a colony (comprised of rooms and tunnels).

At the beginning of the game, all the ants are in the room **##start**. 
The goal is to bring them to the room **##end** with as few moves as possible.

Each room can only contain one ant at a time (except at **##start** and **##end** which can contain as many ants as necessary).

The shortest path isn't necessarily the simplest.  
Some maps will have many rooms and many links, but no path between start and end.  
Some maps will have rooms that link to themselves, sending your path-search spinning in circles.  
Some maps will have too many/too few ants, no start or end, duplicate rooms, links to unknown rooms,  
rooms with invalid coordinates, and a variety of other invalid or poorly-formatted input.  
Ants will also need to avoid traffic jams (walking all over their fellow ants).  

## Usage

1. Install this project
    ```
    $> git clone https://github.com/sashasmir0511/Lem_in.git
    ```
2. Run `make`
3. Run `lem-in`
    ```
   $> ./lem-in < test_map/test1
    ```

## Format map
You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```
For example:
```
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```
This map:  
```
           ______________
          /              \
   -----[5]----[3]----[1] |
  /             |    /    |
[6]-----[0]----[4]  /     |
  \   _________/|  /      |
   \ /         [2]/_______/
   [7]_________/
```
## Output message format
```
Lx-y Lz-w Lr-o ...
```
**x**, **z**, **r** represents the ants’ numbers (going from 1 to **number_of_ants**) and **y**,
**w**, **o** represents the rooms’ names.  
For example:
```
L1-b 
L1-c L2-b 
L1-d L2-c L3-b 
L2-d L3-c 
L3-d 
```