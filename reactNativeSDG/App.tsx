import React from 'react';
import { tileData, TileData } from 'src/data/tileData';
import { NavigationStackItem, Routes, RouteWeight } from 'src/data/types';
import Home from 'src/screens/home';
import Target from 'src/screens/target';

type Props = {};

type State = {
  pageType: Routes;
  navigationStack: NavigationStackItem[];
  homeData: TileData[];
};

export default class App extends React.Component<Props, State> {
  constructor(props: Props) {
    super(props);

    // Initial page is Home (I've defined a Routes.Splash but not setup)
    const pageType = Routes.Home;
    this.state = {
      pageType,
      navigationStack: [{ pageType, pageWeight: RouteWeight[pageType] }],
      homeData: tileData,
    };
  }

  changeRoute = (pageType: Routes) => {
    const stack = this.state.navigationStack;
    const toPageWeight = RouteWeight[pageType];
    let fromPageWeight = stack.length ? stack[stack.length - 1].pageWeight : 0;

    // Cleaning old routes from nav stack
    while (fromPageWeight >= toPageWeight && stack.length) {
      stack.pop();
      fromPageWeight = stack.length ? stack[stack.length - 1].pageWeight : 0;
    }

    stack.push({
      pageType,
      pageWeight: toPageWeight,
    });

    this.setState({ pageType });
  };

  backNav = () => {
    const { navigationStack, pageType } = this.state;
    const prevIndex = navigationStack.length - 2;

    // Already at Home or prev page doesn't exist (i.e. deeplinking)
    if (pageType != Routes.Home && prevIndex >= 0) this.changeRoute(navigationStack[prevIndex].pageType);
  };

  render() {
    const { pageType, homeData } = this.state;
    // If homeData ever changes, need to make sure it's called via setState and
    // not mutated due to 'Home' screen being a PureComponent.

    try {
      switch (pageType) {
        case Routes.Home:
          return <Home data={homeData} onChangeRoute={this.changeRoute} />;
        case Routes.Target:
          return <Target onBack={this.backNav} />;
        default:
          return null;
      }
    } catch (error) {}
  }
}
