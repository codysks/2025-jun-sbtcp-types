.PHONY: test
test:
	$(MAKE) -C test
.PHONY: init_submodules
init_submodules:
	git submodule init
	git submodule update
