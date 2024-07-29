import pandas as pd
city = {"name": ["Bangkok","Chonburi","Ayuthaya","Samuthprakarn","Lopburi","Korat"],
        "population" : [19191919,28282828,37373737,46464646,5555555,12345678], 
        "hospital":[100,20,10,35,69,56]} 
cities = pd.DataFrame(city,columns = ["population","hospital"],index =city["name"])

print(cities[cities["hospital"] > 50])

cities = cities.drop(columns=['population'],index='Chonburi')
print(cities)

population = [19191919,37373737,46464646,5555555,12345678]
cities.insert(loc=0, column="population",value= population)
print(cities)


cities["hospital"].replace({ 100:123, 10:45}, inplace=True)
print(cities)
