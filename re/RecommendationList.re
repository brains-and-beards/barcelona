open ReactNative;

module Style = {
  open ReactNative.Style;
  let container = style([flex(1.), backgroundColor(Colors.white)]);
  let categories =
    style([
      height(60.),
      backgroundColor(Colors.white),
      paddingHorizontal(80.),
      flexDirection(`row),
      justifyContent(`spaceBetween),
      alignItems(`center)
    ]);
};

type state = {filter: Category.filter};

type action =
  | ChangeFilter(Category.filter);

let component = ReasonReact.reducerComponent("RecommendationList");

let make = (_children) => {
  ...component,
  initialState: () => {filter: Category.All},
  reducer: (action, state) =>
    switch action {
    | ChangeFilter(filter) => ReasonReact.Update({...state, filter})
    },
  render: (self) => {
    let currentFilter = self.state.filter;
    let recommendations =
      Array.mapi(
        (index, place) =>
          <RecommendationItem key=("recommendation-" ++ string_of_int(index)) place />,
        Recommendation.filteredRecommendations(currentFilter)
      );
    let onChange = (filter) => self.reduce((_event) => ChangeFilter(filter), ());
    <ScrollView style=Style.container>
      <NavBar />
      <View style=Style.categories>
        <Category filter=All currentFilter onChange />
        <Category filter=(Category(See)) currentFilter onChange />
        <Category filter=(Category(Eat)) currentFilter onChange />
      </View>
      (ReasonReact.arrayToElement(recommendations))
    </ScrollView>
  }
};
