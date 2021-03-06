import sys

class ROT13:
	def __init__(self):
		upperchars = []
		lowerchars = []
		self.charmap = {}

		for i in range(ord('A'), ord('N')):
			charr = chr(i)
			upperchars.append(charr)
			self.charmap[charr] = chr(ord(charr) + 13)
			self.charmap[charr.lower()] = chr(ord(charr) + 13).lower()
		for i in range(ord('N'), ord('Z') + 1):
			charr = chr(i)
			upperchars.append(charr)
			self.charmap[charr] = chr(ord(charr) - 13)
			self.charmap[charr.lower()] = chr(ord(charr) - 13).lower()

		self.charmap[" "] = " "
		# Numerics
		for i in range(ord('0'),ord(':')):
			self.charmap[chr(i)] = chr(i)
		# Basic special ASCII characters
		for i in range(ord('!'),ord('0')):
			self.charmap[chr(i)] = chr(i)
	def process(self,stringg):
		nstr=""
		for i in stringg:
			nstr+=self.charmap[i]
		return nstr

def main():
	r13 = ROT13()

	m_string = ""
	if len(sys.argv) > 1:
		i=False
		for item in sys.argv:
			if i:
				m_string+=item
				m_string+=" "
			else:
				i=True

	result = r13.process(m_string)
	print("Result:", result)
	print("Original:", r13.process(result))

if __name__ == "__main__":
	main()
