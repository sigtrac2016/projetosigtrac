import metacomm.combinatorics.all_pairs2

all_pairs = metacomm.combinatorics.all_pairs2.all_pairs2

parameters = [
                (  [ "TRUE", "FALSE" ] ),
                (  [ "0", "<=30", ">30"] ),
                (  [ "TRUE", "FALSE" ] ),
                (  [ "<=2", ">2"] ),
                (  [ "TRUE", "FALSE" ] ),
                (  [ "TRUE", "FALSE" ] )
             ]


pairwise = all_pairs( parameters, n=3 )

print "PAIRWISE:"
for i, v in enumerate(pairwise):
    # print "%i:\t%s" % (i, str(v))
    print "\t".join(v)
