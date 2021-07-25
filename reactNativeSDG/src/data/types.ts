export enum Routes {
  Home = 'Home',
  Target = 'Target',
  Splash = 'Splash',
}

export const RouteWeight = {
  [Routes.Home]: 1,
  [Routes.Target]: 2,
  [Routes.Splash]: 98,
};

export interface NavigationStackItem {
  pageType: Routes;
  pageWeight: number;
}
