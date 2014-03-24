class Solution:
  # @param s, a string
  # @return a list of strings
  def restoreIpAddresses(self, s):
    self.solution = []
    self.prefix = []
    self.getIPAddress(s, 4)
    return self.solution

  def valid(self, s):
    if not s:
      return False
    if len(s) > 1 and s[0] == '0':
      return False
    num = int(s)
    return True if num >= 0 and num <= 255 else False

  def getIPAddress(self, s, depth):
    # depth:
    # 4   3   2   1
    # 255.255.255.0
    if depth == 1 and self.valid(s):
      self.solution.append('.'.join(self.prefix + [s]))
      # print 'found %s' % self.solution[-1]
      return
    elif depth > 1:
      length = 1
      while length <= len(s) and self.valid(s[0:length]):
        self.prefix.append(s[0:length])
        # wait = raw_input()
        # print 'adding %s, depth = %d' % (s[0:length], depth)
        # print self.prefix
        self.getIPAddress(s[length:], depth-1)
        self.prefix.pop()
        length += 1

sol = Solution()
l = sol.restoreIpAddresses('010010')
print l