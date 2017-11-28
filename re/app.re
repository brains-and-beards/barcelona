let routeConfig: Navigator.routesConfig = {
  "recommendations": {"screen": RecommendationList.jsComponent},
  "place": {"screen": RecommendationList.jsComponent}
};

let component = Navigator.create(~routeConfig);

let app = () => <RecommendationList />;