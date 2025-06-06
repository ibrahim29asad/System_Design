# Prompt
# 9. Create a ticket reservation system for a cinema
#   that shows available seats and books tickets.

#
# My Answer: 
# the idea is to create a ticket system for a movie theater
# So each theater has a name 
# For Simplicity Sake we say that it is a straight 2d run (so a box)
# We have to account for special needs seats that are reserved for it 
# Say the front 1 rows on the side are specail needs 
# each you also have to check if theres x-in a row avaible to account for 
# groups of people 
# Have to give Title for Movie 
# Have to give Time for the movie times so add a buffer of 30 mins each way
# Simplicity sake we can say 1-24 to represent the time 
# No movies can start between 23 and 5 to avoid confusion 

# So this is baiscally a system design question then and 
class Movie:
    # This will automatically add the Time for cleanup and setup
    def __init__(self, name, timeStart, timeEnd):
        self.MovieName = name
        self.StartTime = timeStart
        self.EndTime = timeEnd

class Theater:

    def Theater(self, maxCols, maxRows, Name):
        if maxCols <= 0 or maxRows <= 0:
            print("Values cannot be 0")
            return 
        # if Name in self.MovieTheater:
        #     print("Movie Theater Name Already Exists"):
        #     return 
        room = [[0 for _ in range(maxCols)] for _ in range(maxRows)]


        # theater = [for _ in range(maxCols)]
        return
    
    
    def AddMovie(self, Movie, Theater):
        pass
        
        
        
        





