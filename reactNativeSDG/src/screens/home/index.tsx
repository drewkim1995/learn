import React from 'react';
import { SafeAreaView, ScrollView, View } from 'react-native';
import { Routes } from 'src/data/types';
import Tile from 'src/components/tile';
import { viewStyles } from './styles';
import { TileData } from 'src/data/tileData';

const styles = viewStyles();

type Props = {
  data: TileData[];
  onChangeRoute: (route: Routes) => void;
};

export default class Home extends React.PureComponent<Props> {
  render() {
    const { data, onChangeRoute } = this.props;

    return (
      <SafeAreaView>
        <ScrollView contentInsetAdjustmentBehavior="automatic">
          <View style={styles.flexBox}>
            {data.map((item: TileData, index) => {
              return (
                <Tile
                  key={item.iconUrl}
                  bgUrl={item.bgUrl}
                  iconUrl={item.iconUrl}
                  changeRoute={index === data.length - 1 ? () => onChangeRoute(Routes.Target) : undefined}
                />
              );
            })}
          </View>
        </ScrollView>
      </SafeAreaView>
    );
  }
}
