import os, sys, io
finput = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
fprint = sys.stdout.write