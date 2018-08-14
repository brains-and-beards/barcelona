type screen =
  | Intro
  | Recommendations
  | RecommendationDetails(string);

module StatefullStackNavigator =
  StatefullStackNavigator.Make(
    {
      type navigationState = screen;
      let initialScreen = Intro;
    },
  );

type action =
  | SetActiveRecommendation(string);

type state = {
  navigationState: list(screen),
  activeRecommendation: string,
};

let component = ReasonReact.reducerComponent("App");

let renderScreen = (push, screen) =>
  switch (screen) {
  | Intro => <IntroScreen showRecommendation=(() => push(Recommendations)) />
  | RecommendationDetails(uuid) => <RecommendationDetails placeID=uuid />
  | Recommendations =>
    <RecommendationList
      openDetails=(uuid => push(RecommendationDetails(uuid)))
    />
  };

let headerTitle = screen =>
  switch (screen) {
  | Intro => ""
  | Recommendations => "B&B Recommends"
  | RecommendationDetails(uuid) =>
    let place = Recommendation.find(uuid);
    place.title;
  };

let make = _children => {
  ...component,
  initialState: () => {
    navigationState: [Recommendations],
    activeRecommendation: "",
  },
  reducer: (action, state) =>
    switch (action) {
    | SetActiveRecommendation(title) =>
      ReasonReact.Update({...state, activeRecommendation: title})
    },
  render: ({state, reduce}) =>
    ReasonReact.element @@
    StatefullStackNavigator.make(
      ~getHeaderConfig=headerTitle,
      ~render=renderScreen,
    ),
};

let root =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));