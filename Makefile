all: Trivial SparseTable

Trivial: Trivial.cpp
SparseTable: SparseTable.cpp

clean:
	rm -f Trivial SparseTable
