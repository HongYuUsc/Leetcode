class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> map = new HashMap<>();
        for(String s : strs){
            StringBuilder count = new StringBuilder();
            for(int i=0;i<26;i++){
                count.append('0');
            }
            for(int j=0;j<s.length();j++){
                int k= s.charAt(j)-'a';
                count.setCharAt(k,(char)(count.charAt(k)+1));
            }
            String b = "" + count;
            if(map.containsKey(b)){
                map.get(b).add(s);
            }
            else{
                List<String> l = new ArrayList<String>();
                l.add(s);
                map.put(b,l);
            }
        }
        List<List<String>> str = new ArrayList<List<String>>();
        for(Object key: map.keySet()){
            str.add(map.get(key));
        }
        return str;
    }
}

/*Java String 不能修改，StringBuilder可以
/*StringBuilder 转为 String 使用 "" + sb
/*ContainsKey 是用 == 比较的，不同对象值一样也为false，因为存储的地址不一样
