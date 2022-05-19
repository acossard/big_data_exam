import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_excel('es_e.xlsx', sheet_name=0) 
df = df.rename(columns={'Unnamed: 0': 'Exercise', 'Unnamed: 1': 'e','Unnamed: 2': '#threads', 'Unnamed: 3': 'time',
                       'Unnamed: 4':'pragma'})
df = df[6:]

plt.plot(df.pragma,df.time,'--o')
plt.xlabel('#pragma')
plt.ylabel('time [ms]')
plt.xticks(rotation=45)
plt.savefig('e_time.jpg', bbox_inches = 'tight',dpi=600)

