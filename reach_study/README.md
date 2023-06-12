# reach_study README

This selection of files will help bridge the gap between the reachability scores or certain path points to their associated 
reach scores! The goal is to create a ROS 2 msg that will be comnprised of a PoseArray type msg that contains information about
each of the robots poses and return a list of the associated scores to each pose!

### Notes:
It was determined that the score should be left as how they were calculated in the REACH scoring metric (That is,
unreachable points are given a score of zero whilst other points then have increasing scores based on their reachability
evaltuation. Thuws all of the scores are given a score that will be evaluted with a double to ensure max precision on scores!

The other considered way on returning reach scores based on a normalized scale:
Either something like <br>< 0 ============== 10 ><br> Where 0 is given an evaluation, (Good or bad) and the other number the opposite. this would require us to set a standard for each point along that scale, 
i.e. 10 is un-reachable, 9 just barely reachable, 8 ba little reachable, and so on and so forth and what have you.

In the interest of preserving a standard scale to reach, as well as the ability to further narrow down the scores and standardize them later without fear of losing data in the 
current stage it was deemed better to go with the first option!
