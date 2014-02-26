// pseudo-code for external K-way merge sort
#include <vector>
using std::vector;

// possible implementation of filesize
int filesize(FILE* data) {
  fseek(f, 0, SEEK_END);  // seek to end of file
  size = ftell(f);        // get current file pointer
  fseek(f, 0, SEEK_SET);  // seek back to beginning of file
  return size / 2^30;     // return in GB
}

void ExternalMergeSort(FILE* data,    // pointer to data file
                       FILE* output,  // pointer to output file
                       int mem_size   // size of memory in GB
                       ) {
  int data_size =  filesize(data);
  int num_extern_files = ceil(1.0 * data_size / mem_size);
  int K = num_extern_files;
  vector<FILE*> extern_files(num_extern_files);

  // sort each chunk of data and write to external file
  // chunk size = size of memory
  for (int i = 0; i < num_extern_files; ++i) {
    char fname[80];
    sprintf(fname, "extern_file_%d", i);
    extern_files[i] = fopen(fname, "w");
    char* chunk = get_chunk(data, mem_size, i);
    qsort(chunk);
    fwrite(extern_files[i], chunk);
  }

  int seg_size = mem_size / (K+1);
  char buffer[K][seg_size] = {0}; // each buffer holds a segment of a chunk
  char merge[seg_size] = {0};     // output buffer

  // preload buffer with segments
  for (int i = 0; i < K; ++i) {
    buffer[i] = read_buffer(extern_files[i], mem_size);
  }

  // now perform k-way merge
  int j = 0;
  int count = 0;
  while (true) {
    int value, id;
    // find the max value and id from the buffers
    get_max_value_id(buffer, value, id);
    merge[j++] = value;

    // reload the buffer if it is empty
    if ( empty(buffer[id]) ) {
      if ( empty(extern_files[id]) ) {
        count++;
      } else {
        buffer[id] = read_buffer(extern_files[id], mem_size);
      }

      // all chunks are done, write the remaining and exit
      if (count == K) {
        fwrite(output, merge);
        break;
      }
    }

    // write to output if merge buffer is full
    if ( full(merge) ) {
      fwrite(output, merge);
      clear(merge);
    }
  }
}