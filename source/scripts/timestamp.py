# *****************************************************************************
# *****************************************************************************
#
#		Name :		timestamp.py
#		Purpose :	Create a timestamp for the build.
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		10th January 2020
#
# *****************************************************************************
# *****************************************************************************

from datetime import datetime
print('\t.text\t"{0}"\n'.format(datetime.now().strftime("[%y-%m-%d %H:%M]")))