
.PHONY: all
all: fcfs sjf srtf rr

fcfs:

sjf:

srtf:

rr:

.PHONY: test
test: test-fcfs test-sjf test-srtf test-rr

.PHONY: test-fcfs
test-fcfs: fcfs
	@for i in `ls tests/INPUT*`; do \
		[ -f tests/fcfs$$( echo $$i | tr -d 'A-z/' ) ] && \
		diff -qB \
		tests/fcfs$$( echo $$i | tr -d 'A-z/' ) \
		<( cat $$i | ./fcfs ) || true; \
	done

.PHONY: test-sjf
test-sjf: sjf 
	@for i in `ls tests/INPUT*`; do \
		[ -f tests/sjf$$( echo $$i | tr -d 'A-z/' ) ] && \
		diff -qB \
		tests/sjf$$( echo $$i | tr -d 'A-z/' ) \
		<( cat $$i | ./sjf ) || true; \
	done

.PHONY: test-srtf
test-srtf: srtf 
	@for i in `ls tests/INPUT*`; do \
		[ -f tests/srtf$$( echo $$i | tr -d 'A-z/' ) ] && \
		diff -qB \
		tests/srtf$$( echo $$i | tr -d 'A-z/' ) \
		<( cat $$i | ./srtf ) || true; \
	done

.PHONY: test-rr
test-rr: rr 
	@for i in `ls tests/INPUT*`; do \
		[ -f tests/rr$$( echo $$i | tr -d 'A-z/' ) ] && \
		diff -qB \
		tests/rr$$( echo $$i | tr -d 'A-z/' ) \
		<( cat $$i | ./rr ) || true; \
	done

.PHONY: clean
clean:
	rm -f fcfs sjf srtf rr scheduling.tar.gz

.PHONY: tar
tar:
	tar czf scheduling.tar.gz fcfs.c sjf.c srtf.c rr.c tests

