new:
	./scripts/new_day.sh

build_day:
	@read -p "Enter Day Number: " day; \
		cd build && make Day$$day && cd ..

test:
	@read -p "Enter Test Name: " test; \
	read -p "Enter Day Number (default: latest): " day; \
	if [ -z "$$day" ]; then \
		day=`ls -d kata/Day* | sort -r | head -n 1 | cut -d'/' -f2`; \
	else \
		day=Day$$day; \
	fi; \
	cd build && ./$$day --gtest_filter=*$$test* && cd ..
