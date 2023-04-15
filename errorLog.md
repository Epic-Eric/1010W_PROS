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
