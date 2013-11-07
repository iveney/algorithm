// I think can use brute force or Hash directly if input is small,
// or Trie if not
public class WordFind {
    public class Trie {
        int row = -1; 
        int column = -1;
        Trie [] edges = new Trie [26];
        public Trie() {
            for (int i=0; i<edges.length; i++) 
                edges[i] = null;
        }

        void addWord(String word) {
            if (word.length() == 0) return;

            // recursively add
            char c = word.charAt(0);
            int id = c - 'A';
            if (edges[id] == null) {// add only if no such prefix
                edges[id] = new Trie();
            }
            edges[id].addWord(word.subString(1));
        }

        boolean 
    }

    public String [] findWords(String [] grid, String[] wordList) {
        Trie trie = new Trie();
        String [] values = new String [wordList.length];
        return values;
    }

    public static void main (String [] args)
    {
        String []grid = new String[]{"TEST",
            "GOAT",
            "BOAT"};
        String []wordList = new String[]{"GOAT", "BOAT", "TEST"};

        WordFind wordFind = new WordFind();
        wordFind.findWords(grid, wordList);
    }
}
