SUBTEST_DIRECTORIES = itch

.PHONY = all

all:
	$(foreach subtest_dir, $(SUBTEST_DIRECTORIES), $(MAKE) -C $(subtest_dir))
