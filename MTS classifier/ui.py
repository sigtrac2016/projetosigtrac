import numpy as np
from sklearn.externals import joblib
from Tkinter import *
from sklearn import preprocessing


def _create_circle(self, x, y, r, **kwargs):
    return self.create_oval(x-r, y-r, x+r, y+r, **kwargs)

def classifyMTS():
	clf = joblib.load('models/svmClassifier-scaled.pkl') 
	features = preprocessing.scale(np.array([float(e1.get()), float(e2.get()), float(e3.get()), float(e4.get())]))
	label = int(clf.predict(features)[0])
	canvas = Canvas(master, width=200, height=200, borderwidth=0, highlightthickness=0, bg="white")
	Canvas.create_circle = _create_circle
	canvas.grid()
	print label
	if label == 0:
		canvas.create_circle(100, 120, 50, fill="blue", outline="#DDD", width=4)
		canvas.create_text(100, 120, text='Nao Urgente')  
	elif label == 1:
		canvas.create_circle(100, 120, 50, fill="green", outline="#DDD", width=4)
		canvas.create_text(100, 120, text='Standard')
	elif label == 2:
		canvas.create_circle(100, 120, 50, fill="yellow", outline="#DDD", width=4)
		canvas.create_text(100, 120, text='Urgente')
	elif label == 3:
		canvas.create_circle(100, 120, 50, fill="orange", outline="#DDD", width=4)
		canvas.create_text(100, 120, text='Muito urgente')
	elif label == 4:
		canvas.create_circle(100, 120, 50, fill="red", outline="#DDD", width=4)
		canvas.create_text(100, 120, text='Emergencia')

master = Tk()
master.wm_title("Risco de Morte")
Label(master, text="Frequencia respiratoria").grid(row=0)
Label(master, text="Frequencia cardiaca").grid(row=1)
Label(master, text="Temperatura").grid(row=2)
Label(master, text="spO2").grid(row=3)

e1 = Entry(master)
e2 = Entry(master)
e3 = Entry(master)
e4 = Entry(master)

e1.grid(row=0, column=1)
e2.grid(row=1, column=1)
e3.grid(row=2, column=1)
e4.grid(row=3, column=1)

Button(master, text='Sair', command=master.quit).grid(row=4, column=0, sticky=W, pady=4)
Button(master, text='Classificar', command=classifyMTS).grid(row=4, column=1, sticky=W, pady=4)

mainloop( )
