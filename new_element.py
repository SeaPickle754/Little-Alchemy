isDebug = input("Are you formating the debug file (Blank for yes)")
isWorking = True
if isDebug == "" or isDebug == "y":
    while isWorking:
        with open("bin/Debug/resources/offsets.csv" , "a") as offsetFile:
            offsetFile.write("\n")
            offset = input("Enter the offset of the new element, serparated by a comma: ")
            offset = offset.split(',')
            name = input("Enter the name of the new element, as a string: ")
            string = f"{offset[0]},{offset[1]},{name}"
            string.strip("\n")
            offsetFile.write(string)
            print("Wrote offset sucessfully. 0 errors.")
        with open("bin/Debug/resources/Combinations.csv", "a") as comboFile:
            offset = input("Enter the combonation of the new element, separated by a comma: ")
            offset = offset.split(',')
            product = input("Enter the product of those two reagents: ")
            string = f"{offset[0]},{offset[1]},{product}"
            string.strip("\n")
            string = f"\n{string}"
            comboFile.write(string)
            print("Wrote products successfully.")
        if input("Continue (Blank for yes)") == "":
            isWorking = True
        else:
            isWorking = False