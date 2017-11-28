type routeConfig = {. "screen": ReasonReact.reactClass};

type routesConfig = {. "recommendations": routeConfig, "place": routeConfig};

[@bs.module "react-navigation"] external navigator : routesConfig => ReasonReact.reactClass =
  "StackNavigator";

let create = (~routeConfig) => navigator(routeConfig);