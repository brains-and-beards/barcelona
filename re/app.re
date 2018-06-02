type screen =
  | Recommendations
  | RecommendationDetails(string);

module StatefullStackNavigator =
  StatefullStackNavigator.Make(
    {
      type navigationState = screen;
      let initialScreen = Recommendations;
    },
  );

type action =
  | SetActiveRecommendation(string);

type state = {
  navigationState: list(screen),
  activeRecommendation: string,
};

let component = ReasonReact.reducerComponent("App");

let renderScreen = (~setRecommendation, push, screen) =>
  switch (screen) {
  | RecommendationDetails(_) => <RecommendationDetails />
  | Recommendations =>
    <RecommendationList
      openDetails=(title => push(RecommendationDetails(title)))
    />
  };

let headerTitle = screen =>
  switch (screen) {
  | Recommendations => "Recommendation"
  | RecommendationDetails(_) => "Details"
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
      ~render=
        renderScreen(
          ~setRecommendation=
            reduce((_) => SetActiveRecommendation("Sagrada")),
        ),
    ),
};

let root =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));