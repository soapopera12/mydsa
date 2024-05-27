# 535. Encode and Decode TinyURL
# https://leetcode.com/problems/encode-and-decode-tinyurl

class Codec:

    def __init__(self):
        self.hm = {}   # unordered dictionary
        self.count = -1

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        self.count += 1
        self.hm[self.count] = longUrl
        return "http://tinyurl.com/" + str(self.count)
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        n = len("http://tinyurl.com/")
        val = int(shortUrl[n:]) # actual length
        return self.hm[val]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))