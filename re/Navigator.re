type routeConfig = {. "screen": ReasonReact.reactClass};

type routesConfig = {. "Home": routeConfig, "List": routeConfig, "Details": routeConfig};

type navigatorOptions = {. "headerMode": string};

let routeConfig: routesConfig = {
  "Home": {"screen": RecommendationList.jsComponent},
  "List": {"screen": RecommendationList.jsComponent},
  "Details": {"screen": RecommendationDetails.jsComponent}
};

[@bs.module "react-navigation"]
external navigator : (routesConfig, navigatorOptions) => ReasonReact.reactClass =
  "StackNavigator";

let create = (~routeConfig) => navigator(routeConfig, {"headerMode": "none"});