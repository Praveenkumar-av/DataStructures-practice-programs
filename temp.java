import java.util.Scanner;

public class temp {

    public static void main(String args[]) {

        Contacts obj = new Contacts();

        obj.insert();
    }
}

class Contacts
{
    TrieDataStuture c;

    void insert()
    {
        Scanner scan = new Scanner(System.in);
        int n, i, j;
        String word;

        c = new TrieDataStuture();

        System.out.print("Enter the no. of contacts :");
        n = scan.nextInt();

        for(i=0; i<n; i++)
        {
            word = scan.next();
            c.insert(word);
        }
        System.out.print("Enter the word to search :");
        word = scan.next();

        c.searchSuggestion(word);
    }
}

class TrieDataStuture
{
    TrieNode root = new TrieNode();

    static class TrieNode
    {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd;

        TrieNode()
        {
            for(int i=0;i<26;i++)
                children[i] = null;

            isEnd = false;
        }
    }

    void insert(String word)
    {
        int i, index;
        TrieNode temp= root;
        for( i=0; i<word.length(); i++)
        {
            index = word.charAt(i) - 'a';
            if(temp.children[index] == null)
            {
                temp.children[index] = new TrieNode();
            }
            temp = temp.children[index];
        }
        temp.isEnd = true;
    }

    void searchSuggestion(String word)
    {
        // generates strings starting from 1st character and adds up,
        //  then traverses the trie 
        int index;
        String str = "";
        TrieNode temp = root;
        
        for(int i=0; i<word.length(); i++)
        {
            index = word.charAt(i)-'a';
            
            if(temp.children[index] == null)
                return;
        
            str += word.charAt(i);
            temp = temp.children[index];
            suggestion(temp,str);
        }
    }

    void suggestion(TrieNode temp, String s)
    {
        // generates string with the matching with string 's' provided by searchSuggestion method
    	if(temp != null)
    	{
            if(temp.isEnd)
            {
                System.out.println(s);
            }
    		for(int i=0;i<26;i++)
            {
    		    if(temp.children[i] != null)
    		    {
    		    	suggestion(temp.children[i], s+Character.toString(i+'a'));
    		    }
            }
    	}
    }
}