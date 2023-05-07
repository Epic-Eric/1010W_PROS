# Error Logs:

## Apr 15th: 
### Problem: 
git push origin maste failed, due to "tip of your current branch is behind its remote counterpart". 
### Solution: 
git pull, then "git config pull.rebase true". This rebases the branch. This actually commits on top of the remote branch, maintaining a single branch both locally and remotely (unlike the default behaviour where two different branches are involved - one on local and the other on remote - and, to combine the two, a merge is performed). This is what I wanted, as I just made PurePursuit and I don't want github (the outdated) to overwrite my files. (https://stackoverflow.com/questions/62653114/how-can-i-deal-with-this-git-warning-pulling-without-specifying-how-to-reconci)
### Problem:
main branch not needed anymore
### Solution:
deleted it both locally and on GitHub

## Apr 30th:
### Problem:
The drivetrain motors are wired but I wasn't sure if they are properly reversed, which led to motor conflicts
### Solution:
Tested each motor individually, see which should be reverse but aren't, and then it works perfectly.
### Progress:
Odometry works!

## May 4th:
### Problem:
Started CAD! Set up all the library containing all the parts. However, the add-ins that will be quite helpful for CADding for VEX are hard to download, as the address is: ~/Library/Application Support/Autodesk/Autodesk Fusion 360/API/AddIns, but Autodesk is a non-existent folder.
### Solution:
Reached out for help on VEX CAD Discord.

## May 6th:
### Problem:
Odometry doesn't work. When I move it to the right it is supposed to say an increasing x, but it's decreasing.
### Solution:
I reversed the direction when defining the encoders
### Problem:
Auto is not consistent
### Solution:
Implemented PD - Controller, changed the slew rate, path-planned for the robot to follow