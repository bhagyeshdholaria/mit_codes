import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import warnings

warnings.filterwarnings('ignore')

# dataset = pd.read_csv("C:\\Users\\admin\\Desktop\\Datasets\\WorldCupMatches.csv")
steam = pd.read_csv("C:\\Users\\admin\\Desktop\\Datasets\\steam_app_data.csv")
# print(dataset.head(5))
# print(dataset.tail(5))

print("Shape: ", steam.shape)  # prints no. of columns x rows
print(steam.info())  # column info with datatypes

# print(dataset.index)
# print(dataset.columns)
# print(dataset.sample(5))                       #randomly picking 5 tuples
# dataset.sort_values(["Datetime","Stage"])      # to sort column wise
# print(steam.head(5))

# print(steam.isnull().sum())                  # gets no. of null values in each column
# print(dataset.dropna(inplace = True))          # drops null values
# print(dataset.isnull().sum())


# print(dataset.iloc[0:3,0:3])                    # to print particular rows & columns


# print("Mean: ",steam['required_age'].mean())
# print("Median: ",steam['required_age'].median())
# print("Mode: ",steam['required_age'].mode())
# print(steam['required_age'].replace(np.NaN,steam['required_age'].mean()).sample(10))    #replace null with mean
# print(dataset['Year'].tail())

# steam.duplicated(subset = None, keep = False).value_counts()
# s_bool = steam.duplicated(subset = None, keep = False)
# print(steam[~s_bool])
# steam.hist(steam["steam_appid"])
steam["steam_appid"].plot.hist()
