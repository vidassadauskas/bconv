default:
	@echo "Please specify a target:"
	@echo "    make tru64 - to build the program on HP Tru64 UNIX"
	@echo "    make linux - to build the program on Linux"

tru64:
	@echo "Making for tru64"
	@make -f Makefile.tru64 tru64

linux:
	@echo "Making for linux"
	@make -f Makefile.linux linux
