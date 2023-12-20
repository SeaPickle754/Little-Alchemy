import csv
isDebug = input("Are you formating the debug file (Blank for yes)")
if isDebug == "" or isDebug == "y":
    with open("bin/Debug/resources/offsets.csv" , "a") as offsetFile:
        offsetWriter = csv.writer(offsetFile)
        offsetFile.write("\n")
        offset = input("Enter the offset of the new element, serparated by a comma: ")
        offset = offset.split(',')
        name = input("Enter the name of the new element, as a string: ")
        offsetWriter.writerow([offset[0],offset[1],name])
        print("Wrote offset sucessfully. 0 errors.")
    with open("bin/Debug/resources/Combinations.csv", "a") as comboFile:
        comboWriter = csv.writer(comboFile)
        comboFile.write("\n")
        offset = input("Enter the combonation of the new element, separated by a comma: ")
        offset = offset.split(',')
        product = input("Enter the product of those two reagents: ")
        comboWriter.writerow([offset[0], offset[1], product])
        print("Wrote products successfully.")
     