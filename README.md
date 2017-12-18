# BBallTeamProj
A basketball stat keeping program written in C++.

Each .cpp and .h file are needed for the program to compline correctly. This application also reads in from a text file titled "bballin.txt" and will create a new txt file called "bballout.txt" when the program is finished.


## What is needed:
#### - A "bballin.txt" file
  - This file is what is read into the program for the beginning players and stats. 
  - Looks like this:
  
  [![Screenshot](https://s33.postimg.org/7b779rdb3/Screenshot_55.png)](https://postimg.org/image/f3xv1qja3/)
  
-The file is formatted as:
 - First line: #ofPlayers #ofGames
 - Following Lines:
   - Jersey# LastName, FirstName // only one line of name and jersey # per player
   - 3pt attemtps 3pt makes 2pt attempts 2pt makes FT attempts FT makes // a line of "stats" for each game that is played
#### DO NOT HAVE A bballout.txt FILE ALREADY CREATED
  - If for any reason you have a bballout.txt file already created, save it to another name, or this application will clear its contents and rewrite the final stats of the team
   
   
   ## What this application does
   #### Print
    - Print total number of games, and total number of players
    - Prints each individual player and their stats for each game, along with the total points they've scored
   #### Add Game
    - Ablility to maually add game stats for each player
   #### Display Player
    - Prints stats report for an individual player
    - Given a jersey number to look up, searches for jersey number and returns stat line if found
   #### Remove Player
    - Removes player from team
   #### Sort by Name and Jersey
    - Sorts players on team by increasing jersey number, or alphabetically
