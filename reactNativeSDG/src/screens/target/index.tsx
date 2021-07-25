import React, { useEffect, useState } from 'react';
import { ActivityIndicator, BackHandler, FlatList, Text, View } from 'react-native';

type Props = {
  onBack: () => void;
};

const Target = (props: Props) => {
  const [isLoading, setLoading] = useState(true);
  const [data, setData] = useState<any>([]);

  useEffect(() => {
    async function apiGetRequest(url: string): Promise<any> {
      const resp = await fetch(url);
      if (resp.ok && resp.status === 200 && resp.headers.get('Content-Type') === 'application/json; charset=utf-8')
        return await resp.json();
      else {
        console.log(resp);
        throw new Error('bad response || not 200 status code');
      }
    }

    function sortJson(json: any[]) {
      let titles: { key: any; title: any }[] = [];
      json.forEach((element) => {
        if (element.goal == '13') titles.push({ key: element.code, title: element.title });
      });
      setData(titles);
    }

    apiGetRequest('https://unstats.un.org/SDGAPI/v1/sdg/Target/List?includechildren=false')
      .then((json) => sortJson(json))
      .catch((error) => console.error(error))
      .finally(() => setLoading(false));

    const backAction = () => {
      props.onBack();
      return true;
    };

    const backHandler = BackHandler.addEventListener('hardwareBackPress', backAction);
    return () => backHandler.remove();
  }, []);

  return (
    <View style={{ flex: 1, padding: 24 }}>
      {isLoading ? (
        <ActivityIndicator size="large" color="00ff00" />
      ) : (
        <FlatList data={data} renderItem={({ item }) => <Text>{item.title}.</Text>} />
      )}
    </View>
  );
};

export default Target;
