import subprocess
path = "cmake-build-debug/MPI_Sorting"

arguments = []
arguments.append(path)
arguments.append(1)
arguments.append(4)
arguments.append(1)

runsTypeElements = [[1, 1, 1000000], [1, 4, 1], [1, 2, 1000000], [1, 4, 1], [1, 3, 1000000]]
    #[100, 1, 10000], [1, 4, 1], [100, 2, 10000], [1, 4, 1], [100, 3, 10000],
    #[10, 1, 100000], [1, 4, 1], [10, 2, 100000], [1, 4, 1], [10, 3, 100000],
    #[1, 1, 1000000], [1, 4, 1], [1, 2, 1000000], [1, 4, 1], [1, 3, 1000000]]

print(arguments)
for inputSet in range(len(runsTypeElements)):
    arguments[1]=str(runsTypeElements[inputSet][0])
    arguments[2]=str(runsTypeElements[inputSet][1])
    arguments[3]=str(runsTypeElements[inputSet][2])
    print(arguments)
    subprocess.check_call(arguments)


