import requests

print("\nhttps://github.com/ph-fox\n~By Anikin Luke")
print("_"*30)
ip = input("Enter ip: ")
url = 'http://'+ip
line = '_'*70

def on(ui, url):
	if ui == "00":
		ui = ui.replace('00','b')
	url = url+'/'+ui+'on'
	r = requests.get(url)
	print(f"[{r.status_code}] {ui} is On")


def off(ui, url):
	if ui == "00":
		ui = ui.replace('00','b')
	url = url+'/'+ui+'off'
	r = requests.get(url)
	print(f"[{r.status_code}] {ui} is Off")


try:
	r = requests.get(url)
	if r.status_code == 200:
		while True:
			print("""
 __[~ By Anikin Luke ~]__
|                        |
|   00 == BuiltinLED     |
|   0 == D0 | GPIO16     |
|   1 == D1 | GPIO5      |
|   2 == D2 | GPIO4      |
|   3 == D3 | GPIO0      |
|   4 == D4 | GPIO2      |
|   5 == D5 | GPIO14     |
|   6 == D6 | GPIO12     |
|   7 == D7 | GPIO13     |
|   8 == D8 | GPIO15     |
|________________________|""")
			ui = input('~> ')
			ui2 = input("on/off: ").lower()
			if ui2 == "on":
				on(ui, url)
			elif ui2 == "off":
				off(ui, url)

except Exception as e:
	print("Error!, connection failed \n{}\n{}\n{}".format(line,e,line))
