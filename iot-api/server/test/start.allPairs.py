import metacomm.combinatorics.all_pairs2
all_pairs = metacomm.combinatorics.all_pairs2.all_pairs2

parameters = [
                (  [ "TRUE", "FALSE" ] ),
                (  [ "<=30", ">30"] ),
                (  [ "TRUE", "FALSE" ] ),
                (  [ "<=3", ">3"] ),
                (  [ "TRUE", "FALSE" ] ),
                (  [ "TRUE", "FALSE" ] )
             ]


pairwise = all_pairs( parameters )

print "PAIRWISE:"
for i, v in enumerate(pairwise):
    # print "%i:\t%s" % (i, str(v))
    print ",".join(v)
