import os
path = "./"

all = []
for root,d_names,f_names in os.walk(path):
	if root == './GENERATE': continue
	print("[{}]".format(root[2:]))
	for f in f_names:
		if f == 'gen_contents.py': continue

		print(os.path.join(root, f) + '\t' + os.path.splitext(f)[0])
	print()