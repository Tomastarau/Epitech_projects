#!/bin/bash
cd antman/
./antman ../test_file/toto 1 > compressed.data
cd ../giantman
./giantman ../antman/compressed.data 1 > compressed_2.data
cd ..

compressed_size=$(wc -c < "antman/compressed.data")
original_size=$(wc -c < "test_file/toto")
compression_percentage=$(bc <<< "scale=2; ($compressed_size/$original_size * \
100)")

if cmp -s test_file/toto giantman/compressed_2.data ;
then
    echo "The Giantman output is the same as the original test file.
The file was compressed and reduced to $compression_percentage% of its \
original size."
else
    echo "The Giantman output is different from the original test file."
fi