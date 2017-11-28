let routeConfig: Navigator.routesConfig = {
  "recommendations": {"screen": RecommendationList.jsComponent},
  "place": {"screen": RecommendationList.jsComponent}
};

let app = Navigator.create(~routeConfig);