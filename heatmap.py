import streamlit as st
import pandas as pd
import seaborn as sns
from sklearn import datasets
from sklearn.ensemble import RandomForestClassifier
import os
import matplotlib.pyplot as plt
import matplotlib
st.set_option('deprecation.showPyplotGlobalUse', False)

st.write("""
# FULLY DIGITISED BUS RESERVATION SYSTEM""")

st.sidebar.header('Slide To Adjust Number of Passengers')

st.sidebar.write("""**Mambakam**""")
JT_0 = st.sidebar.slider('Kovalam', 0, 50, 5, key="1")
AT_0 = st.sidebar.slider('Tambaram', 0, 50, 12, key="2")
JU_0 = st.sidebar.slider('VIT Chennai', 0, 50, 20, key="3")
OT_0 = st.sidebar.slider('Chromepet', 0, 50, 16, key="4")
data_0= (JT_0,AT_0,JU_0,OT_0)

st.sidebar.write("""**Pondicherry**""")
JT_1 = st.sidebar.slider('Kovalam', 0, 50, 7, key="5")
AT_1 = st.sidebar.slider('Tambaram', 0, 50, 12, key="6")
JU_1 = st.sidebar.slider('VIT Chennai', 0, 50, 19, key="7")
OT_1 = st.sidebar.slider('Chromepet', 0, 50, 17, key="8")
data_1 = (JT_1,AT_1,JU_1,OT_1)

st.sidebar.write("""**Railway Station**""")
JT_2 = st.sidebar.slider('Kovalam', 0, 50, 9, key="9")
AT_2 = st.sidebar.slider('Tambaram', 0, 50, 15, key="10")
JU_2 = st.sidebar.slider('VIT Chennai', 0, 50, 22, key="11")
OT_2 = st.sidebar.slider('Chromepet', 0, 50, 18, key="12")
data_2 = (JT_2,AT_2,JU_2,OT_2)

st.sidebar.write("""**Airport**""")
JT_3 = st.sidebar.slider('Kovalam', 0, 50, 5, key="13")
AT_3 = st.sidebar.slider('Tambaram', 0, 50, 17, key="14")
JU_3 = st.sidebar.slider('VIT Chennai', 0, 50, 20, key="15")
OT_3 = st.sidebar.slider('Chromepet', 0, 50, 19, key="16")
data_3 = (JT_3,AT_3,JU_3,OT_3)

st.sidebar.write("""**Others**""")
JT_4 = st.sidebar.slider('Kovalam', 0, 50, 10, key="17")
AT_4 = st.sidebar.slider('Tambaram', 0, 50, 19, key="18")
JU_4 = st.sidebar.slider('VIT Chennai', 0, 50, 17, key="19")
OT_4 = st.sidebar.slider('Chromepet', 0, 50, 20, key="20")
data_4 = (JT_4,AT_4,JU_4,OT_4)


data = [(data_0),(data_1),(data_2),(data_3),(data_4)]

df = pd.DataFrame(data, columns=['Kovalam','Tambaram','VIT Chennai','Chromepet'],index=['Mambakam','Pondicherry','Railway Station','Airport','Others'])
st.subheader('Customer Indices')
st.write(df)

a = st.write(sns.heatmap(df,annot=True, cmap="RdYlGn"))
plt.gcf()
if st.button('Download Customers Dataframe',key="1"):
    df.to_csv("D:\\customer.csv")
if st.button('Download Customer Heatmap',key="2"):
    plt.savefig("Bus_reservation.png")
st.pyplot()

st.subheader('Correlation Stats')

dfc = df.corr()

st.write(dfc)

b = st.write(sns.heatmap(dfc,annot=True, cmap="RdYlGn"))
plt.gcf()   
if st.button('Download Correlation Dataframe',key="3"):
    dfc.to_csv("D:\\bus_corr.csv")
if st.button('Download Correlation Heatmap',key="4"):
    plt.savefig("bus_Correlation.png")
st.pyplot()
st.set_option('deprecation.showPyplotGlobalUse', False)